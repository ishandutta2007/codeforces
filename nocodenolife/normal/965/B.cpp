#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int n, k;
    cin>>n>>k;
    char board[n][n];
    int max = -1;
    int idx_x = -1, idx_y = -1;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>board[i][j];
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int answer = 0;
            if(board[i][j]=='#')
            {
                if(answer>max)
                {
                    max = answer;
                    idx_x = i;
                    idx_y = j;
                }
                continue;
            }
            int up = 0;
            int temp = i-1;
            while(temp>=0)
            {
                if(board[temp][j]=='.')
                {
                    up++;
                    temp--;
                }
                else
                    break;
                if(up==k-1)
                    break;
            }
            temp = i+1;
            int down=0;
            while(temp<n)
            {
                if(board[temp][j]=='.')
                {
                    down++;
                    temp++;
                }
                else
                    break;
                if(down==k-1)
                    break;
            }
            
            int rem = k;
            rem-=(up+1);
            rem = down - rem + 1;
            if(rem>0)
                answer+= rem;
                
            up = 0;
            temp = j-1;
            while(temp>=0)
            {
                if(board[i][temp]=='.')
                {
                    up++;
                    temp--;
                }
                else
                    break;
                if(up==k-1)
                    break;
            }
            temp = j+1;
            down=0;
            while(temp<n)
            {
                if(board[i][temp]=='.')
                {
                    down++;
                    temp++;
                }
                else
                    break;
                if(down==k-1)
                    break;
            }
            
            rem = k;
            rem-=(up+1);
            rem = down - rem + 1;
            if(rem>0)
                answer+= rem;
            
            if(answer>max)
                {
                    max = answer;
                    idx_x = i;
                    idx_y = j;
                }
            
        }
    }
    cout<<idx_x+1<<" "<<idx_y+1<<endl;
    return 0;
}