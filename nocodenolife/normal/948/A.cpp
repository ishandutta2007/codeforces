#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include<iomanip>
using namespace std;


int main(){
    int i,j,answer=1;
    cin>>i>>j;
    char meadow[i][j];
    for(int r=0;r<i;r++)
    {
        for(int c=0;c<j;c++)
        {
            cin>>meadow[r][c];
            if(r>0)
            {
                if((meadow[r][c]=='S'&&meadow[r-1][c]=='W')||(meadow[r][c]=='W'&&meadow[r-1][c]=='S'))
                {
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            if(c>0)
            {
                if((meadow[r][c]=='S'&&meadow[r][c-1]=='W')||(meadow[r][c]=='W'&&meadow[r][c-1]=='S'))
                {
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            
        }
    }
    for(int r=0;r<i;r++)
    {
        for(int c=0;c<j;c++)
        {
            if(meadow[r][c]=='S')
            {
                if(r>0&&meadow[r-1][c]=='.')
                    meadow[r-1][c]='D';
                if(r<i-1&&meadow[r+1][c]=='.')
                    meadow[r+1][c]='D';
                if(c>0&&meadow[r][c-1]=='.')
                    meadow[r][c-1]='D';
                if(c<j-1&&meadow[r][c+1]=='.')
                    meadow[r][c+1]='D';
            }
        }
    }
    cout<<"Yes"<<endl;
    for(int r=0;r<i;r++)
    {
        for(int c=0;c<j;c++)
        {
            cout<<meadow[r][c];
        }
        cout<<endl;
    }
    return 0;
}