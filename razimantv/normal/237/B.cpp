# include <cstdio>
# include <iostream>
# include <algorithm>
# include <vector>
# include <cmath>
# include <queue>
# include <cstring>
# include <cctype>

using namespace std;

int cnt[50],mat[50][50];
vector<int> U,V,W,X;

int main()
{
	int N;
	cin>>N;

	for(int i=0;i<N;i++)
		cin>>cnt[i];

	for(int i=0;i<N;i++)
		for(int j=0;j<cnt[i];j++)
			cin>>mat[i][j];

	int tot=0,next=1;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<cnt[i];j++,next++)
		{
			if(mat[i][j]!=next)
			{
				for(int k=0;k<N;k++)
				{
					for(int l=0;l<cnt[k];l++)
					{
						if(mat[k][l]==next)
						{
							swap(mat[i][j],mat[k][l]);
							U.push_back(i);
							V.push_back(j);
							W.push_back(k);
							X.push_back(l);
							tot++;
							goto BPP;
						}
					}
				}
BPP:;
			}
		}
	}

	cout<<tot<<endl;
	for(int i=0;i<tot;i++)
		cout<<U[i]+1<<"\t"<<V[i]+1<<"\t"<<W[i]+1<<"\t"<<X[i]+1<<endl;
	return 0;
}