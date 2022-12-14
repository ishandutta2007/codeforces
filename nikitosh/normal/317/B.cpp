#include<cstdio>
#include<vector> 

using namespace std;

int n, t, a[1005][1005], b[1005][1005], x, y, boo;
vector < pair <int, int> > ans;

int main()
{                                    
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &t);
	a[64][64] = n;
	for (int g = 0; g < 40000; g++)
	{
		ans.clear();
		boo = 0;
		for (int i = 0; i < 129; i++)
			for (int j = 0; j < 129; j++)
				if (a[i][j] >= 4)
				{
					a[i][j] -= 4;
					ans.push_back(make_pair(i - 1, j));
					ans.push_back(make_pair(i + 1, j));
					ans.push_back(make_pair(i, j - 1));
					ans.push_back(make_pair(i, j + 1));
					boo = 1;
				}
		for (int i = 0; i < (int) ans.size(); i++)
        	a[ans[i].first][ans[i].second]++;
        if (boo == 0)
	   		break;
	}
	for (int i = 0; i < t; i++)
	{
    	scanf("%d%d", &x, &y);
        if (x > -65 && x < 65 && y > -65 && y < 65)
        {
            //printf("AAA");
        	printf("%d\n", a[64 + x][64 + y]);
    	}
    	else
    		printf("0\n");
    }
	return 0;
}