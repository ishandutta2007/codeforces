#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    
    char board[n][m];
    int up[n][m] ;
    int down[n][m];
    int left[n][m];
    int right[n][m];
    int hor[n][m];
    int ver[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>board[i][j];
            up[i][j] = 0;
            down[i][j] = 0;
            left[i][j] = 0;
            right[i][j] = 0;
            hor[i][j] = 0;
            ver[i][j] = 0;
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
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(i>0 && board[i-1][j]=='.')
            {
                up[i][j] = 0;
            }
            else
            {
                up[i][j] = up[i-1][j]+1;
            }
            if(j>0 && board[i][j-1]=='.')
            {
                left[i][j] = 0;
            }
            else
            {
                left[i][j] = left[i][j-1]+1;
            }
        }
    }
    
    for(int i=n-2;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
        {
            if(i<n-1 && board[i+1][j]=='.')
            {
                down[i][j] = 0;
            }
            else
            {
                down[i][j] = down[i+1][j]+1;
            }
            if(j<m-1 && board[i][j+1]=='.')
            {
                right[i][j] = 0;
            }
            else
            {
                right[i][j] = right[i][j+1]+1;
            }
        }
    }

    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout<<down[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]!='.')
            {
                int len = min( min(up[i][j],down[i][j]), min(left[i][j],right[i][j]));
                if(len>0)
                {
                    answer.push_back(i);
                    answer.push_back(j);
                    answer.push_back(len);
                }
            }
        }
    }

    
    int ans = answer.size()/3;
    
    for (int i=0;i<ans;i++) {
        int x = answer[3*i];
        int y = answer[3*i+1];
        int len = answer[3*i+2];
        ++ver[x - len][y];
        if (x + len  < n-1)
            --ver[x + len + 1][y];
        ++hor[x][y - len];
        if (y + len < m-1)
            --hor[x][y + len + 1];  
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i > 0) ver[i][j] += ver[i - 1][j];
            if (j > 0) hor[i][j] += hor[i][j - 1];
            if (ver[i][j] > 0 || hor[i][j] > 0)
            {
                if(board[i][j]=='.')
                {
                    cout<<"-1"<<endl;
                    return 0;
                }
            }
            else
            {
                if(board[i][j]!='.')
                {
                    cout<<"-1"<<endl;
                    return 0;
                }
            }
        }
    }
    
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         if(board[i][j] == '*')
    //         {
    //             cout<<"-1"<<endl;
    //             return 0;
    //         }
    //     }
    // }
    cout<<ans<<endl;
    for(int i=0;i<ans;i++)
    {
        cout<<answer[3*i]+1<<" "<<answer[3*i+1]+1<<" "<<answer[3*i+2]<<endl;
    }
    
    return 0;
}