#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
set<string>st;
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<(int)s.size();i++)
    {
        s.push_back(s.front());
        s=s.substr(1);
        st.insert(s);
    }
    cout<<(int)st.size()<<endl;
    return 0;
}