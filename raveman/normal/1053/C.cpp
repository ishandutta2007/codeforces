#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back	

int n,q;
int a[222222];
int w[222222];

const int mod = 1000000007;

struct Node{
	Node(){
		l=r=0;
		lf=rg=0;
		sumw=sumaw=sumap=0;
	}
	ll sumw;
	ll sumaw;
	ll sumap;
	int l,r;
	Node* lf;
	Node* rg;
};

void changeW(Node* curr, int pos,int val){
	if(pos<curr->l || pos>curr->r) return;
	if(curr->l==curr->r){
		curr->sumw=val;
		curr->sumaw=val*ll(a[pos]);curr->sumaw%=mod;
		curr->sumap=val*ll(pos);curr->sumap%=mod;
	}else{
		changeW(curr->lf,pos,val);
		changeW(curr->rg,pos,val);
		curr->sumw=curr->lf->sumw+curr->rg->sumw;
		curr->sumaw=curr->lf->sumaw+curr->rg->sumaw;curr->sumaw%=mod;
		curr->sumap=curr->lf->sumap+curr->rg->sumap;curr->sumap%=mod;
	}
}

ll getSum(Node* curr,int l, int r){
	if(r<curr->l || l>curr->r) return 0;
	if(l<=curr->l && curr->r<=r) return curr->sumw;
	ll sum=0;
	sum += getSum(curr->lf,l,r);
	sum += getSum(curr->rg,l,r);
	return sum;
}

int findPos(Node* curr,ll sum){
	if(curr->l==curr->r) return curr->l;
	if(curr->lf->sumw>=sum) return findPos(curr->lf,sum);
	return findPos(curr->rg,sum-curr->lf->sumw);
}

ll moveall_left(Node* root,int from,int to,int pos){
	if(to<root->l || from>root->r) return 0;
	if(from<=root->l && root->r<=to){
		ll sum = root->sumap + root->sumw % mod * ll(pos - root->r);
		sum%=mod;if(sum<0)sum+=mod;
		sum -= root->sumaw;
		sum%=mod;
		if(sum<0)sum+=mod;
		return sum;
	}


	ll res = 0;
	res += moveall_left(root->rg,from,to,pos);
	int sub = 0;
	int t1 = max(from,root->rg->l);
	int t2 = min(to,root->rg->r);
	if(t1<=t2)sub=(t2-t1+1);
	res += moveall_left(root->lf,from,to,pos-sub);

	return res % mod;
}

ll moveall_right(Node* root,int from,int to,int pos){
	//cout<<root<<' '<<root->l<<' '<<root->r<<' '<<from<<' '<<to<<' '<<pos<<endl;
	if(to<root->l || from>root->r) return 0;
	if(from<=root->l && root->r<=to){
		//cout<<root->sumap<<' '<<root->suma<<' '<<pos - root->l<<' '<<root->sumaw<<endl;
		ll sum = root->sumap + root->sumw % mod * ll(pos - root->l);
		//cout<<sum<<endl;
		sum%=mod;if(sum<0)sum+=mod;
		sum = root->sumaw - sum;sum%=mod;
		if(sum<0)sum+=mod;
		return sum;
	}


	ll res = 0;
	res += moveall_right(root->lf,from,to,pos);
	int sub = 0;
	int t1 = max(from,root->lf->l);
	int t2 = min(to,root->lf->r);
	if(t1<=t2)sub=(t2-t1+1);
	res += moveall_right(root->rg,from,to,pos+sub);

	return res % mod;
}

Node* buildTree(int l,int r){
	Node* curr = new Node();
	curr->l = l;
	curr->r = r;
	if (l != r){
		curr->lf = buildTree(l,(l+r)/2);
		curr->rg = buildTree((l+r)/2+1,r);
		curr->sumw = curr->lf->sumw + curr->rg->sumw;
		curr->sumaw = curr->lf->sumaw + curr->rg->sumaw;curr->sumaw%=mod;
		curr->sumap = curr->lf->sumap + curr->rg->sumap;curr->sumap%=mod;
	}else{
		curr->sumw = w[l];
		curr->sumaw = w[l] * ll(a[l]); curr->sumaw%=mod;
		curr->sumap = w[l] * ll(l); curr->sumap %= mod;
	}
	return curr;
}


ll stupid(ll x,ll y){
	ll sum=0;
	FOR(i,x,y+1)sum+=w[i];
	ll s2=0;
	FOR(i,x,y+1){
		s2 += w[i];
		if(s2*2>=sum){
			ll res=0;
			int p1 = a[i];
			for(int j=i-1;j>=x;j--){
				p1--;
				res += abs(a[j]-p1) * ll(w[j]);
			}
			int p2 = a[i];
			for(int j=i+1;j<=y;j++){
				p2++;
				res += abs(a[j]-p2) * ll(w[j]);
			}
			return res%mod;
		}
	}
	return -1;
}
int X[222222],Y[222222];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>q;
	REP(i,n)scanf("%d",a+i);
	REP(i,n)scanf("%d",w+i);
	REP(i,q)scanf("%d %d",X+i,Y+i);
	/*
start:
	cout<<"start"<<endl;
	n=rand()%10+1;
	q=rand()%10+1;
	REP(i,n)a[i]=rand()%10+1,a[i]+=(i?a[i-1]:0);
	REP(i,n)w[i]=rand()%10+1;
	REP(i,q){
		if(rand()%2){
			X[i]=-(rand()%n+1);
			Y[i]=rand()%10+1;
		}else{
			X[i]=rand()%n;
			Y[i]=rand()%n;
			if(X[i]>Y[i])swap(X[i],Y[i]);
		}
	}
	
	REP(i,n)cout<<a[i]<<' ';puts("");
	REP(i,n)cout<<w[i]<<' ';puts("");
	*/
	Node* root = buildTree(0,n-1);

	REP(i,q){
		int x=X[i],y=Y[i];
		if(x<0){
			x=-x;
			x--;

			changeW(root,x,y);
			// change w[x] yo y
			w[x]=y;
		}else{
			x--,y--;

			ll sum = getSum(root,0,x-1);
			ll sum2 = getSum(root,x,y);
			ll m = sum + (sum2+1)/2;
			ll pos = findPos(root,m);
			ll rpos = a[pos];

			//cout<<sum<<' '<<sum2<<' '<<m<<' '<<pos<<' '<<rpos<<endl;

			ll ans = 0;
			ans += moveall_left(root,x,pos-1,rpos-1);
			//cout<<"a1 "<<ans<<endl;
			ans += moveall_right(root,pos+1,y,rpos+1);
			//cout<<"a2 "<<ans<<endl;
			ans %= mod;
			// compute sum of A on (x,M)
			//
			printf("%I64d\n",ans);
			/*
			ll st = stupid(x,y);
			if(st!=ans){
				cout<<st<<endl;
				puts("FUCK");
				return 0;
			}*/
		}
	}

	//goto start;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}