#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
map<string,int> XD;
int xs=0;
char tmp[1000];
string tt[2020];
inline int gn(){
    scanf("%s",tmp);
    if(XD.find(tmp)==XD.end()){
        tt[xs]=tmp;
        return XD[tmp]=xs++;
    }
    return XD[tmp];
}
int in[1010][3];
int ed[2020][2020];
int main(){
    int n,d,i,j;
    scanf("%d%d",&n,&d);
    for(i=0;i<n;i++){
        int c;
        in[i][0]=gn();
        in[i][1]=gn();
        scanf("%d",&c);
        in[i][2]=c;
    }
    for(i=0;i<n;i++)for(j=0;j<n;j++){
        if(i==j)continue;
        if(in[i][0]==in[j][1]&&in[j][0]==in[i][1]&&in[j][2]-in[i][2]<=d&&in[j][2]-in[i][2]>0)ed[in[i][0]][in[i][1]]=1;
    }
    int cnt=0;
    for(i=0;i<xs;i++)for(j=i+1;j<xs;j++)if(ed[i][j]||ed[j][i])cnt++;
    printf("%d\n",cnt);
    for(i=0;i<xs;i++)for(j=i+1;j<xs;j++)if(ed[i][j]||ed[j][i])printf("%s %s\n",tt[i].c_str(),tt[j].c_str());
}