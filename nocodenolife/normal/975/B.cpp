#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    long long int board[14];
    long long int use[14];
    for(int i=0;i<14;i++)
        cin>>board[i];
    long long int max =0;
    for(int x=0;x<14;x++)
    {
        long long int ans=0;
        for(int i=0;i<14;i++)
            use[i]=board[i];
        int start =x;
        long long int beads = use[x];
        use[x]=0;
        long long int addall = beads/14;
        beads = beads%14;
        for(int i=0;i<14;i++)
        {
            use[i]+=addall;
        }
        while(beads)
        {
            start = (start+1)%14;
            use[start]++;
            beads--;
        }
        for(int i=0;i<14;i++)
        {
            if(use[i]%2==0)
                ans+=use[i];
        }
        if(ans>max)
            max = ans;
    }
    cout<<max<<endl;
    return 0;
}