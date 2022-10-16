#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%i %i",&n,&m);
    queue<int> q1,q2;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        q1.push(a);
    }
    for(int i=0;i<m;i++)
    {
        int a;
        scanf("%i",&a);
        q2.push(a);
    }
    int cnt=0;
    while(!q1.empty()&&!q2.empty())
    {
        int tr=q1.front();
        int tr2=q2.front();
        if(tr2>=tr)
        {
            q2.pop();
            cnt++;
        }
        q1.pop();
    }
    printf("%i\n",cnt);
    return 0;
}