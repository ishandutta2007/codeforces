#include <iostream>

using namespace std;

string w;

bool sprawdz(string a)
{
    int n=a.length();
    for(int i=0;i<a.length()/2;i++)
    {
        if(a[i]==a[n-1-i] || abs(a[i]-a[n-i-1])==2) continue;
        else return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k>>w;
        if(sprawdz(w)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}