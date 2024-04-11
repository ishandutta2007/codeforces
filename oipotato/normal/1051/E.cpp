#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
#include<stack>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
const int MOD=998244353;
void get_next(char *a, int *next) {
    int i,j,k;
    int n=strlen(a);
    for (j=0;j+1<n && a[j]==a[j+1];j++);
    next[1]=j; k=1;
    for(i=2;i<n;i++) { 
        int len=k+next[k],l=next[i-k];
        if (l<len-i)next[i]=l;
        else {
            for(j=max(0,len-i);i+j<n && a[j]==a[i+j];j++);
            next[i]=j; k=i;
        }
    }
}
void ExtendedKMP(char *a,char *b,int *next,int *ret) {
    get_next(a,next);
    int n=strlen(a),m=strlen(b);
    int i,j,k;
    for(j=0;j<n && j<m && a[j]==b[j];j++);
    ret[0]=j; k=0;
    for(i=1;i<m;i++) {
        int len=k+ret[k],l=next[i-k];
        if (l<len-i)ret[i]=l;
        else {
            for(j=max(0,len-i);j<n && i+j<m && a[j]==b[i+j];j++);
            ret[i]=j; k=i;
        }
    }
}
int cal(char a[],int pos,char s[],int len,int pre[])
{
    if(pre[pos]==len)return 0;
    return a[pos+pre[pos]]<s[pre[pos]+1]?-1:1;
}
const int N=1000010;
char a[N],l[N],r[N];
int nxt[N],L[N],R[N],f[N],s[N];
int main()
{
    scanf("%s",a+1);
    scanf("%s",l+1);
    scanf("%s",r+1);
    ExtendedKMP(l+1,a+1,nxt+1,L+1);
    ExtendedKMP(r+1,a+1,nxt+1,R+1);
    int n=strlen(a+1),nl=strlen(l+1),nr=strlen(r+1);
    // rep(i,n)printf("%d%c",L[i]," \n"[i==n]);
    // rep(i,n)printf("%d%c",R[i]," \n"[i==n]);
    s[1]=1;
    rep(i,n)
    {
        int x=i-nr+1,y=i-nl+1;
        if(x>=1&&cal(a,x,r,nr,R)==1)x++;
        if(y>=1&&cal(a,y,l,nl,L)==-1)y--;
        x=max(x,1);y=max(y,0);
        // printf("%d %d %d\n",i,x,y);
        f[i]=(s[y]-s[x-1]+MOD)%MOD;
        if(y==i&&a[i]=='0')(f[i]+=f[i-1])%=MOD;
        s[i+1]=s[i];
        if(a[i+1]!='0')(s[i+1]+=f[i])%=MOD;
    }
    printf("%d\n",f[n]);
	return 0;
}