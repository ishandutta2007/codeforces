# include <cstdio>
# include <iostream>
# include <algorithm>
# include <vector>
# include <cstring>
# include <cctype>
# include <set>
# include <map>

using namespace std;

char used[100][26],inp[101];

int main()
{
    int M,N;
    scanf("%d%d",&M,&N);
    
    for(int i=0;i<M;i++)
    {
        scanf("%s",inp);
        for(int j=0;j<N;j++)
            used[j][inp[j]-'A']=1;
    }
    
    long long ret=1;
    for(int i=0;i<N;i++)
    {
        int cnt=0;
        for(int j=0;j<26;j++)
            cnt+=used[i][j];
        ret=(ret*cnt)%1000000007;
    }
    cout<<ret<<endl;
    return 0;
}