#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
int n;
vector<int> niz;
void check(){
    for(int i=1;i<niz.size();i++)
        if(abs(niz[i]-niz[i-1])>1){
            printf("NO\n");
            exit(0);
        }
}
int max(){
    int m=0;
    for(int i=0;i<niz.size();i++)
        m=max(niz[i],m);
    return m;
}
vector<int>::iterator find(){
    vector<int>::iterator it=niz.begin();
    while(*it!=max())
        *it++;
    return it;
}
void solve()
{
    while(niz.size())
    {
        check();
        niz.erase(find());
    }
    printf("YES\n");
}
void read(){
    scanf("%i",&n);
    niz.resize(n);
    for(int i=0;i<n;i++)
        scanf("%i",&niz[i]);
}
int main()
{
    read();
    solve();
}