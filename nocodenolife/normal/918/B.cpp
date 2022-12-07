
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    string names[n];
    int first[n];
    int second[n];
    int third[n];
    int fourth[n];
    char thrown;
    for(int i=0;i<n;i++)
    {
        cin>>names[i]>>first[i]>>thrown>>second[i]>>thrown>>third[i]>>thrown>>fourth[i];
    }
    
    for(int j=0;j<m;j++)
    {
        string command;
        cin>>command;
        int ip_1,ip_2,ip_3,ip_4;
        cin>>ip_1>>thrown>>ip_2>>thrown>>ip_3>>thrown>>ip_4>>thrown;
        for(int i=0;i<n;i++)
        {
            if((first[i]==ip_1)&&(second[i]==ip_2)&&(third[i]==ip_3)&&(fourth[i]==ip_4))
            {
                cout<<command<<" "<<first[i]<<"."<<second[i]<<"."<<third[i]<<"."<<fourth[i]<<"; #"<<names[i]<<endl;
            }
        }
    }
    
    return 0;
}