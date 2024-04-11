/*#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main() {
    int i,j,n,ans[1005][10],room=0,p=0;
    memset(ans,0,sizeof(ans));
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        getchar();
        scanf("%c%c%c%c%c%c%c",&ans[i][0],&ans[i][1],&ans[i][2],&ans[i][3],&ans[i][4],&ans[i][5],&ans[i][6]);
        for(j=0; j<=6; j++)
            ans[i][j]-='0';
    }
    for(i=0;i<=6;i++)
    {
        room=0;
        for(j=1;j<=n;j++)
        {
            if(ans[j][i]==1)
                room++;
        }
        p=max(p,room);
    }
    printf("%d",p);
    return 0;
}
 */
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;
int ans[10], n;
int main(){
    cin>>n;
    cin.get();
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<7; j++)
            if(s.at(j)=='1') ans[j]++;
    }
    int mmax=0;
    for(int i=0; i<7; i++)
        mmax=max(ans[i], mmax);
    cout<<mmax<<endl;
    return 0;
}