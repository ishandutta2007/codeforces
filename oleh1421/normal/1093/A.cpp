#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    vector<int>ans;
    while(t--) {
        int x; cin>>x;
        ans.push_back(x/2);
    }
    for (int i=0;i<ans.size();i++) cout<<ans[i]<<endl;

    return 0;
}