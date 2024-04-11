#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")


#include <bits/stdc++.h>
using namespace std;

#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll int
#define lll __int128
#define pb(a) push_back(a)
#define mt make_tuple
typedef long double ld;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10, 18);
ll modulo = pow(10,9) + 7;

#define MAX 3'000'010

ll mn[MAX];
ll mnidx[MAX];
ll lz[MAX];

void init(ll node, ll l, ll r){
	mn[node] = 0;
	lz[node] = 0;
	mnidx[node] = l;
	if(l == r){
		return;
	}
	init(node<<1, l, (l+r)/2);
	init(((node<<1)|1), (l+r)/2+1, r);
}

void pull(ll node){
	ll li = (node<<1), ri = ((node<<1)|1);
	lz[node] = 0;
	if(mn[li] < mn[ri]){
		mn[node] = mn[li];
		mnidx[node] = mnidx[li];
	}
	else{
		mn[node] = mn[ri];
		mnidx[node] = mnidx[ri];
	}
}

void push(ll node, ll l, ll r){
	if(l != r){
		lz[node<<1] += lz[node];
		lz[(node<<1)|1]+=lz[node];
	}
	mn[node]+=lz[node];
	lz[node] = 0;
}

void upd(ll node, ll l, ll r, ll lu, ll ru, ll val){
	push(node, l, r);
	if(r < lu || ru < l){
		return;
	}
	if(lu <= l && r <= ru){
		lz[node] += val;
		push(node, l, r);
		return;
	}
	upd((node<<1), l, (l+r)/2, lu, ru, val);
	upd(((node<<1)|1), (l+r)/2 + 1, r, lu, ru, val);
	pull(node);
}

void que(ll node, ll l, ll r, ll ql, ll qr, ll& bst, ll& id){
	push(node, l, r);
	if(r < ql || qr < l){
		return;
	}
	if(ql <= l && r <= qr){
		if(mn[node] < bst){
			bst = mn[node];
			id = mnidx[node];
		}
		return;
	}
	que((node<<1), l , (l+r)/2, ql, qr, bst, id);
	que(((node<<1)|1) , (l+r)/2 + 1, r, ql, qr, bst, id);
}

ll fen[MAX];

void updTillStart(ll id, ll val){
	while(id){
		fen[id]+=val;
		id-=id&-id;
	}
}

ll queTillEnd(ll id){
	ll s =0;
	while(id < MAX){
		s+=fen[id];
		id+=id&-id;
	}
	return s;
}

long long countinv(vector<pair<ll,ll> >& arr){
	ll n = arr.size();
	long long ans = 0;
	ll st = 0;
	while(st < n){
		ll nd = st;
		while(nd < n && arr[nd].ff == arr[st].ff){
			++nd;
		}
		for(ll i = st; i<nd; i++){
			ans+=queTillEnd(arr[i].ss+1);
		}
		for(ll i = st; i<nd; i++){
			updTillStart(arr[i].ss + 1, 1);
		}
		st = nd;
	}
	
	for(auto& el : arr){
		updTillStart(el.ss + 1, -1);
	}
	
//	cout<<"we have "<<ans<<" inversions "<<endl;
	return ans;
}

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n, m;
		cin>>n>>m;
		vector<pair<ll, ll> > a1(n);
		vector<ll> a2(m);
		fori(n){
			ll ed;
			cin>>ed;
			a1[i] = mp(ed, i);
		}
		fori(m){
			cin>>a2[i];
		}
		a1.pb(mp(inf, n));
		
		n = a1.size();	//!!!
		sort(a1.begin(), a1.end());
		sort(a2.begin(), a2.end());
		// root is at 1 , range is [0 ... n]
		init(1, 0, n);
		
		ll ptl = -1, ptr = n;
		{
			for(ll i = n-1; i >= 0; i--){
				if(a1[i].ff > a2[0]){
					ptr = i;
					ll ind = a1[i].ss;
					upd(1, 0, n, ind+1, n, 1);
//					cout<<"we ll add +1 from "<<ind+1<<" up to "<<n<<endl;
				}
			}
		}
		long long ans = 0;
		ll left = 0;
		fori(m){
			while(a1[ptl+1].ff < a2[i]){
				++ptl;
				ll ind = a1[ptl].ss;
//				cout<<"+1 from "<<0<<" up to and including "<<ind<<endl;
				upd(1, 0, n, 0, ind, 1);
			}
			while(a1[ptr].ff <= a2[i]){
				ll ind = a1[ptr].ss;
//				cout<<"-1 from "<<ind+1<<" up to and including "<<n<<endl;
				upd(1, 0, n, ind+1, n, -1);
				++ptr;
			}
			ll cur= inf;
			ll curid = -1;
			que(1, 0, n, left, n, cur, curid);
			left = curid;
			ans+=cur;
//			cout<<"ptl is "<<ptl<<" ptr is "<<ptr<<endl;
//			cout<<"best index came out as "<<left<<" ans came out as "<<cur<<endl;
		}
		ans+=countinv(a1);
		cout<<ans<<'\n';
	}
}


int main()  {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}