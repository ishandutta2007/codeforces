#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> a(n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    while(!a.empty())
    {
        if(a.front()<=k)
            a.erase(a.begin());
        else if(a.back()<=k)
            a.pop_back();
        else break;
    }
    return 0*printf("%d\n",n-(int)a.size());
}