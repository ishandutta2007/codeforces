// @author peter50216
// #includes {{{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<limits.h>
#include<ctype.h>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
// }}}
char a[201000],b[201000];
int next[201000][30];
int lx[201000],rx[201000];
int cnt[30][201000];
inline bool solve(){
    int al=strlen(a),bl=strlen(b);
    if(al<bl)return 0;
    int i,j;
    for(i=0;i<26;i++)next[al][i]=al;
    for(i=al-1;i>=0;i--){
        for(j=0;j<26;j++){
            next[i][j]=next[i+1][j];
        }
        next[i][a[i]-'a']=i;
    }
    if(a[0]!=b[0])return 0;
    lx[0]=0;
    for(i=1;i<bl;i++){
        int s=next[lx[i-1]+1][b[i]-'a'];
        if(s==al)return 0;
        lx[i]=s;
    }
    for(i=0;i<26;i++)next[0][i]=0;
    for(i=1;i<=al;i++){
        for(j=0;j<26;j++){
            next[i][j]=next[i-1][j];
        }
        next[i][a[i-1]-'a']=i;
    }
    if(a[al-1]!=b[bl-1])return 0;
    rx[bl-1]=al-1;
    for(i=bl-2;i>=0;i--){
        int s=next[rx[i+1]][b[i]-'a'];
        if(s==0)return 0;
        rx[i]=s-1;
    }
    for(i=0;i<bl;i++){
        cnt[b[i]-'a'][lx[i]]++;
        cnt[b[i]-'a'][rx[i]+1]--;
    }
    for(j=0;j<26;j++){
        for(i=1;i<al;i++){
            cnt[j][i]+=cnt[j][i-1];
        }
    }
    for(i=0;i<al;i++)if(cnt[a[i]-'a'][i]==0)return 0;
    return 1;
}
int main(){
    scanf("%s%s",&a,&b);
    puts(solve()?"Yes":"No");
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread