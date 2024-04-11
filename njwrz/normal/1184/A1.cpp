#include<bits/stdc++.h>
using namespace std;
#define SC scanf
#define PR printf
#define pb push_back
#define mp make_pair
#define SZ(v) ((int)(v).size())
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF=0x3f3f3f3f;
const ll LL_INF=0x3f3f3f3f3f3f3f3f;
const int xx[4]={1,-1,0,0};
const int yy[4]={0,0,1,-1};
int inline in(){
	int x=0,c;
	for(;(unsigned int)((c=getchar())-'0')>=10;){
		if(c=='-')return -in();
		if(!~c)throw ~0;
	}
	do{
		x=(x<<3)+(x<<1)+(c-'0');
	}while((unsigned int)((c=getchar())-'0')<10);
	return x;
}
int main(){
    ios::sync_with_stdio(false);
    ll r;
    cin>>r;
    ll x=-1,y=-1;
    for(x=1;(x+1)*(x+1)<=r;x++){
    	if((r-(x+1)*(x+1))%x!=0);
    	else{
    		if(((r-(x+1)*(x+1))/x+1)%2!=0);
    		else{
    			y=((r-(x+1)*(x+1))/x+1)/2;
    			break;
			}
		}
	}
	if(y==-1)puts("NO");
	else cout<<x<<' '<<y<<endl;
	return 0;
}