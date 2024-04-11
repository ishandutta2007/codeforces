
#include <bits/stdc++.h>
using namespace std;
int main()
{
     int n,k;
     vector<int>data;
     cin>>n>>k;
     for(int i=0;i<n;i++)
     data.push_back(i);
     int p=0;
     for(int i=0;i<k;i++)
     {
        int step,d;
        cin>>step;
        d=(p+step)%n;
        cout<<data[d]+1<<" ";
        n--;
        data.erase(data.begin()+d);
        p=d;
     }
     cout<<endl;
     return 0;
}