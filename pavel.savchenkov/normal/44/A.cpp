#include <cstdio>
    #include <iostream>
    #include <algorithm>
    #include <set>
    #include <string>
    using namespace std;

    int main() {
            //freopen("input.txt","r",stdin);
            int n; scanf("%d\n",&n); set <string> q; string s; string ss;
            for (int i=1;i<=n;i++)
            {
             cin>>s; cin>>ss; s+=" "+ss; q.insert(s); //scanf("\n");
            }
            cout << (int)q.size();
            return 0;
    }