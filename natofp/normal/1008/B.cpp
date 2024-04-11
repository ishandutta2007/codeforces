#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int akt=1000000000;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        int c=min(a,b);
        int d=max(a,b);
        if(d<=akt) akt=d;
        else
        {
            if(c<=akt) akt=c;
            else {cout<<"NO"; return 0;}
        }
    }
    cout<<"YES";
    return 0;
}