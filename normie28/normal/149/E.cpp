#include<bits/stdc++.h>
using namespace std;
const int N = (int) 2e5 + 10; 
int f[N],lenp,lent,pos[N],ans=0,n;
char p[N],t[N];
void getnxt() {
    f[0]=f[1]=0;
    for(int i=1,j=0;i<lenp;i++) {
        j=f[i];
        while(j&&p[i]!=p[j]) j=f[j];
        f[i+1]= p[i]==p[j]?j+1:0;
    }
}
 
int find(int ok) {
    for(int i=0,j=0;i<lent;i++) {
        while(j&&p[j]!=t[i]) j=f[j];
        if(p[j]==t[i]) {
            if(!ok&&pos[j]==-1) pos[j]=i;
            if(ok&&lenp-j-2>=0&&pos[lenp-j-2]!=-1&&pos[lenp-j-2]<=lent-i-2) 
                return 0,ans++;
            j++;
        }
        if(!ok&&j>=lenp) return 0;
    }
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>t;lent=strlen(t);
    cin>>n;
    for(int i=1;i<=n;i++) {
        memset(pos,-1,sizeof (pos));
        cin>>p;
	lenp=strlen(p);
        getnxt();
	find(0);
        reverse(t,t+lent);
	reverse(p,p+lenp);
        getnxt();
	find(1);
        reverse(t,t+lent);
    }
	cout<<ans;
}