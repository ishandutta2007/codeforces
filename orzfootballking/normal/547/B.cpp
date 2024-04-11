#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int l[200005],r[200005],a[200005],n,ans[200005],st[200005],top; 
set<P<int,int> >::iterator iter;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n){
        while(top&&a[st[top]]>a[i]){
            r[st[top]]=i-1;
            top--;
        }
        st[++top]=i;
    }
    while(top){
        r[st[top]]=n;
        top--;
    }
    for(int i=n;i>=1;i--){
        while(top&&a[st[top]]>a[i]){
            l[st[top]]=i+1;
            top--;
        }
        st[++top]=i;
    }
    while(top){
        l[st[top]]=1;
        top--;
    }
    FOR(i,1,n)ans[r[i]-l[i]+1]=max(ans[r[i]-l[i]+1],a[i]);
	for(int i=n;i>=1;i--){
		ans[i]=max(ans[i],ans[i+1]);
	}
	FOR(i,1,n)cout<<ans[i]<<' ';
	RE 0;
}