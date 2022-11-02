#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n, a,b,c,d;
        cin>>n>>a>>b>>c>>d;
        if(n*(a-b)>c+d) cout<<"NO"<<endl;
        else if(n*(a+b)<c-d) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}