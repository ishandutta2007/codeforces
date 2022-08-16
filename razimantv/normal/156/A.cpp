# include <cstdio>
# include <iostream>
# include <algorithm>
# include <vector>
# include <cstring>
# include <cctype>
# include <set>
# include <map>
# include <cmath>
# include <string>

using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    for(int i=0;i<b.size();i++)
        a="#"+a+"#";
    
    int L=a.size(),M=b.size();
    int best=0;
    for(int i=0;i+M<=L;i++)
    {
        int cnt=0;
        for(int j=0;j<M;j++)
            if(a[i+j]==b[j])cnt++;
        best=max(cnt,best);
    }
    cout<<M-best<<endl;
    return 0;
}