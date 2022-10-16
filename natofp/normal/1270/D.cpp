#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int pos,val;
const int nax=505;
int bez[nax];

void zap(vector<int> a)
{
    cout<<"? "<<" ";
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i];
        if(i!=a.size()-1) cout<<" ";
    }
    cout<<endl;
    fflush(stdout);
    cin>>pos>>val;
}

int m=0;

vector<int> war;





int main()
{
    int n,k; cin>>n>>k;
    vector<int> a;
    for(int i=1;i<=k+1;i++)
    {
        a.clear();
        for(int j=1;j<=k+1;j++)
        {
            if(i==j) continue;
            a.push_back(j);
        }
        zap(a);
        bez[i]=val;
        war.push_back(bez[i]);
    }
    sort(war.begin(),war.end());
    int kurwa=war.back();
    for(int i=0;i<war.size();i++)
    {
        if(war[i]==kurwa) m++;
    }
    cout<<"! "<<m<<endl;
    fflush(stdout);
    return 0;
}