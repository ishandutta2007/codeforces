# include <algorithm>
# include <cctype>
# include <cmath>
# include <cstdio>
# include <cstring>
# include <iostream>
# include <set>
# include <vector>

using namespace std;
    
int main()
{
    int N,M,A;
    scanf("%d%d%d",&N,&M,&A);
    long long ret=N/A+(N%A?1:0);
    ret*=M/A+(M%A?1:0);
    cout<<ret<<"\n";
    return 0;
}