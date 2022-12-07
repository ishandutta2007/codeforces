
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i = 1;
    int j = 1;
    vector<int> fib;
    fib.push_back(1);
    while(i<=2000)
    {
        int temp = i;
        i = i+j;
        j = temp;
        fib.push_back(i);
        //cout<<i<<endl;
    }
    int n;
    cin>>n;
    i = 0;
    int prev = fib[i];
    for(int co=1;co<=n;co++)
    {
        if(co==prev)
        {
            i++;
            prev = fib[i];
            cout<<"O";
        }
        else
            cout<<"o";
    }
    cout<<endl;
    return 0;
}