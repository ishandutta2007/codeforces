#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int n,m;
    scanf("%i %i",&n,&m);
    vector<string> s(n);
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
    }
    int res=0;
    for(int col=0;col<m;col++)
    {
        bool sorted=true;
        for(int i=0;i<n-1;i++)
        {
            if(s[i].substr(0,col+1)>s[i+1].substr(0,col+1))
                sorted=false;
        }
        if(!sorted)
        {
            res++;
            for(int i=0;i<n;i++)
            {
                //if(m-res>0)
                s[i]=s[i].substr(0,col)+s[i].substr(col+1,m-col-1);
                    //cout << s[i] << "\n";
            }
            col--;
        }
    }
    printf("%i\n",res);
    return 0;
}