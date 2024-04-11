#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool a[505][505];
int main()
{
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;cin>>c;
            a[i][j]=(c=='*');
        }
    }
    int x=0;
    int y=0;
    for (int i=2;i<=n && x==0;i++){
        for (int j=2;j<m && x==0;j++){
            if (a[i][j] && a[i][j-1] && a[i][j+1] && a[i-1][j] && a[i+1][j]){
                x=i;
                y=j;
            }
        }
    }
    if (x==0) {
        cout<<"NO";
        return 0;
    }
    int curx=x-1;
    while (a[curx][y]){
        a[curx][y]=0;
        curx--;
    }
    curx=x+1;
    while (a[curx][y]){
        a[curx][y]=0;
        curx++;
    }
    int cury=y-1;
    while (a[x][cury]){
        a[x][cury]=0;
        cury--;
    }
    cury=y+1;
    while (a[x][cury]){
        a[x][cury]=0;
        cury++;
    }
    a[x][y]=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j]){
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
    return 0;
}
//1-0
//3-1
//5-2
//7 3
//9 4