#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
char tmp[50];
string t;
string a,b,c;
int main(){
    scanf("%s",tmp);
    int ans=-1;
    int i,l=strlen(tmp),j;
    t=tmp;
    for(i=1;i<l&&i<=7;i++){
        for(j=1;i+j<l&&j<=7;j++){
            a=t.substr(0,i);
            b=t.substr(i,j);
            c=t.substr(i+j);
            if(a.size()>7||b.size()>7||c.size()>7)continue;
            if(a.size()>1&&a[0]=='0')continue;
            if(b.size()>1&&b[0]=='0')continue;
            if(c.size()>1&&c[0]=='0')continue;
            int aa=atoi(a.c_str());
            int bb=atoi(b.c_str());
            int cc=atoi(c.c_str());
            if(aa>1000000||bb>1000000||cc>1000000)continue;
            if(aa+bb+cc>ans)ans=aa+bb+cc;
        }
    }
    printf("%d\n",ans);
}