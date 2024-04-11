#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y;
    cin>>x>>y;
    if(x==y)
    {
    	cout<<"="<<endl;
    	return 0;
    }
    long double a = log(x)/x;
    long double b = log(y)/y;
    //cout<<a<<" "<<b<<endl;
    if(a>b)
    	cout<<">"<<endl;
    else if(b>a)
    	cout<<"<"<<endl;
    else
    	cout<<"="<<endl;

    return 0;
}