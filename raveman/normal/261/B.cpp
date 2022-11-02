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

int n,p;
int a[55];
int c[55];
int d[55];

double res;

int ch[55],zn[55];

void addf(int *x,int f){
	for(int i=2;i<=f;i++)x[i]++;
}
void add(){

	REP(i,n+1){
		int x = min(ch[i],zn[i]);
		ch[i]-=x;
		zn[i]-=x;
	}
	double val = 1;
	REP(i,n+1){
		while(ch[i]) val *= i,ch[i]--;
		while(zn[i]) val /= i,zn[i]--;
	}

	//cout<<"add "<<val<<endl;
	res += val;
}

void go(int currlen,int pos,int num,bool addd){
	if(addd){
		//cout<<"! "<<currlen<<' '<<pos<<' '<<num<<' '<<addd<<endl;
		int bad = 0;
		REP(i,currlen+1)bad+=c[i]-d[i];

		CL(ch,0),CL(zn,0);
		int lf = n - num;

		if(bad!=lf){
		//	cout<<currlen<<endl;
			//FOR(i,1,6) cout<<d[i]<<endl;
			//cout<<lf<<' '<<bad<<endl;
			ch[lf-bad]++;
			for(int i=lf-1;i>=2;i--) ch[i]++;

			for(int i=1;i<pos;i++){
				addf(ch,c[i]);
				addf(zn,d[i]);
				addf(zn,c[i]-d[i]);
			}
			ch[num]++;
			addf(ch,num);
			addf(zn,n);
			add();
		}
	}

	if(pos<=50){
		for(int i=0;i<=c[pos];i++){
			if(i*pos>currlen) break;
			d[pos] = i;
			go(currlen-i*pos,pos+1,num+i,i>0);
			d[pos]=0;
		}
	}
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	
	cin>>n;
	int sum = 0;
	REP(i,n) cin>>a[i],c[a[i]]++,sum+=a[i];
	cin>>p;

	if(sum<=p) cout<<n<<endl;
	else{
		go(p,1,0,0);
		printf("%.10lf\n",res);
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}