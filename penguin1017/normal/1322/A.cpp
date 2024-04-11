#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
char s[N];
int l,r;
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	rep(i,0,n)if(s[i]=='(')l++;
	else r++;
	if(l!=r){
		cout<<-1;
		return 0;
	}
	int ans=0,sum=0,last=-1;
	rep(i,0,n){
		if(s[i]==')')sum++;
		else sum--;
		if(!sum){
			if(s[i]=='('){
				ans+=i-last;
			}
			last=i;
		}
	}
	cout<<ans;
}