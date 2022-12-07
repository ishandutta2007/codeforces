#include<iostream>

using namespace std;

int main()
{
	int k;
	cin>>k;

	while(k>0)
	{
		int first_row = -1;
		int second_row;
		int first_col = -1;
		int second_col;

		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				char c;
				cin>>c;
				if(c=='K')
				{
					if(first_col==-1)
					{
						first_row = i;
						first_col = j;
					}
					else
					{
						second_col = j;
						second_row = i;
					}
				}
			}
		}

		int dif_row = second_row - first_row;
		int dif_col = second_col - first_col;

		if(dif_row<0)
			dif_row*=-1;

		if(dif_col<0)
			dif_col*=-1;

		if(dif_col%4==0 && dif_row%4==0)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}

		k--;
	}

	return 0;
}