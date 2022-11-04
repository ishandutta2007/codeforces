#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    set<string>st;
    string str;
    cin>>str;
    st.insert(str);
    cout<<str<<" ";
    cin>>str;
    st.insert(str);
    cout<<str<<"\n";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>str;
        st.erase(str);
        cin>>str;
        st.insert(str);
        cout<<*st.begin()<<" ";
        cout<<*(--st.end())<<"\n";
    }
    return 0;
}