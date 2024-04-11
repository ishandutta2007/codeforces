#include <iostream>

using namespace std;

int N,X[3010],Y[3010],result,flag[2010][2010];

int main()
{
	cin >> N;
	for (int i=0;i<N;i++)
	{
		cin >> X[i] >> Y[i];
		flag[X[i]+1000][Y[i]+1000]=1;
	}
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
			if (i!=j&&(X[i]+X[j])%2==0&&(Y[i]+Y[j])%2==0&&flag[(X[i]+X[j])/2+1000][(Y[i]+Y[j])/2+1000])
				result++;
	cout << result/2 << endl;
	return 0;
}