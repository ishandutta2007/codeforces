#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

bool p(string s){
     string s1=s;
     reverse(s1.begin(),s1.end());
     if (s==s1) return 1;
     return 0;
}
int main()
{
    int t;
    cin>>t;
    vector<string>ans;
    while(t--) {
        string s1;
        cin>>s1;
        string s=s1;
        sort(s.begin(),s.end());
        if (p(s)) ans.push_back("-1");
        else ans.push_back(s);
    }
    for (int i=0;i<ans.size();i++) cout<<ans[i]<<endl;

    return 0;
}