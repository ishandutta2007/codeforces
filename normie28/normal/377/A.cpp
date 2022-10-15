#include <bits/stdc++.h>
 
using namespace std;
 
const int mod=1e9+7;
double rast(int x1,int y1,int x2,int y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
 
 
char s[505][505];
int n,m,k;
bool used[505][505];
int c,kol;
bool flag2;
 
bool prov(int x,int y)
{
    return (x>=0 && x<n && y>=0 && y<m);
}
 
void rec(int x,int y)
{
    if (flag2) return;
    if (!prov(x,y)) return;
    if (used[x][y]) return;
    if (s[x][y]=='#') return;
 
    used[x][y]=true;
    c++;
    if (c==kol)
    {
        flag2=true;
        return;
    }
 
    rec(x+1,y);
    rec(x,y+1);
    rec(x-1,y);
    rec(x,y-1);
}
 
int main()
{
 
    ios_base::sync_with_stdio(false);
 
    cin >> n >> m >> k;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            cin >> s[i][j];
            if (s[i][j]=='.')
                kol++;
        }
    kol-=k;
 
    bool flag=false;
    for (int i=0;i<n && !flag;i++)
        for (int j=0;j<m && !flag;j++)
            if (s[i][j]=='.')
            {
                rec(i,j);
                flag=true;
            }
 
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        if (!used[i][j] && s[i][j]=='.')
        s[i][j]='X';
 
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
            cout << s[i][j];
        cout << '\n';
    }
}