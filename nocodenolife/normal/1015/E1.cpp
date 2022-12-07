#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    
    char board[n][m];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>board[i][j];
        }
    }
    if(board[0][0]=='*'|| board[n-1][m-1]=='*')
    {
        cout<<"-1"<<endl;
        return 0;
    }
    if(board[0][m-1]=='*'|| board[n-1][0]=='*')
    {
        cout<<"-1"<<endl;
        return 0;
    }
    vector<int> answer;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]!='.')
            {
                int len = 0;
                int max = min(i,j);
                max = min(max,n-i-1);
                max = min(max,m-j-1);
                
                for(len = 1;len<= max;len++)
                {
                    if((board[i][j+len]!='.')&&(board[i][j-len]!='.')&&(board[i+len][j]!='.')&&(board[i-len][j]!='.'))
                    {
                        board[i][j+len] = '+';
                        board[i][j-len] = '+';
                        board[i][j] = '+';
                        board[i+len][j] = '+';
                        board[i-len][j] = '+';
                        continue;
                    }
                    else
                        break;
                }
                len--;
                
                if(len>0)
                {
                    answer.push_back(i+1);
                    answer.push_back(j+1);
                    answer.push_back(len);
                }
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j] == '*')
            {
                cout<<"-1"<<endl;
                return 0;
            }
        }
    }
    
    int ans = answer.size()/3;
    cout<<ans<<endl;
    for(int i=0;i<ans;i++)
    {
        cout<<answer[3*i]<<" "<<answer[3*i+1]<<" "<<answer[3*i+2]<<endl;
    }
    
    return 0;
}