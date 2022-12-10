#include<bits/stdc++.h>
#define pb push_back
#define pp pop_back()
#define mp make_pair
#define fr first
#define sc second
#define sz size()
#define smin(x,y) ((x)=min((x),(y)))
#define smax(x,y) ((x)=max((x),(y)))
#define all(x) x.begin(),x.end()
#define CS ios_base::sync_with_stdio(false);
#define show(x) cerr << #x << " is " << x <<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi; 

const int M=1e5+5;
const int C=30;
int seg[C][4*M],
	lazy[C][4*M];
int num[C];
int n;

int get(int kar,int ql,int qr,int l=0,int r=n,int id=1){
	if(r<=ql || qr<=l) return 0;
	if(ql<=l && r<=qr) return seg[kar][id];
	int mid = (l+r)/2;
	if(~lazy[kar][id]){
		lazy[kar][2*id] = lazy[kar][2*id+1] = lazy[kar][id];
		seg[kar][2*id] = lazy[kar][id] * (mid-l);
		seg[kar][2*id+1] = lazy[kar][id] * (r-mid);
		lazy[kar][id]=-1;
	}
	int u = get(kar,ql,qr,l,mid,2*id);
	int v = get(kar,ql,qr,mid,r,2*id+1);
	return u+v;
}

void upd(int kar,int ql,int qr,int val,int l=0,int r=n,int id=1){
	if(r<=ql || qr<=l) return;
	if(ql<=l && r<=qr){
		seg[kar][id] = (r-l)*val;
		lazy[kar][id] = val;
		return;
	}
	int mid = (l+r)/2;
	if(~lazy[kar][id]){
		lazy[kar][2*id] = lazy[kar][2*id+1] = lazy[kar][id];
		seg[kar][2*id] = lazy[kar][id] * (mid-l);
		seg[kar][2*id+1] = lazy[kar][id] * (r-mid);
		lazy[kar][id]=-1;
	}
	upd(kar,ql,qr,val,l,mid,2*id);
	upd(kar,ql,qr,val,mid,r,2*id+1);
	seg[kar][id] = seg[kar][2*id] + seg[kar][2*id+1];
	return;
}

int32_t main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int q; cin>>n>>q;
	string s; cin>>s;
	memset(lazy,-1,sizeof lazy);
	for(int i=0;i<n;i++)
		upd((int)(s[i]-'a'),i,i+1,1);
	while(q--){
		int l,r; cin>>l>>r; l--;
		memset(num,0,sizeof num);
		int odd=0 , ido, su = 0;
		for(int i=0;i<25;i++){
			num[i] = get(i,l,r);
			if(num[i]&1)
				odd++,ido=i;
			su += num[i];
		}
		num[25] = (r - l) - su;
		if(num[25] & 1)
		    odd++, ido = 25;
		int lz = (r-l)&1;
		if(lz != odd) continue;
		int nl=l,nr=r;
		for(int i=0;i<26;i++){
			if(!num[i]) continue;
			int g = num[i]>>1;
			upd(i,l,r,0);
			upd(i,nl,nl+g,1);
			upd(i,nr-g,nr,1);
			nl+=g;
			nr-=g;
		}
		if(lz) upd(ido,nl,nr,1);
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<26;j++)
			if(get(j,i,i+1)){
				char c = 97+j;
				cout<<c;
				break;
			}
	return cout<<endl,0;
}