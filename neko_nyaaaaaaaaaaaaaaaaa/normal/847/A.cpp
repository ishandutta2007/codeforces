#include <iostream>

using namespace std;

struct AHelper
{
	int left;
	int right;
};

int main()
{
	int n;
	cin >> n;
	AHelper ah[101];
	bool sel[101] = { false };
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		ah[i].left = a;
		ah[i].right = b;
	}
	int rmost = 0;
	AHelper* lmost = NULL;
	for (int i = 1; i <= n; i++)
		if (!sel[i])
		{
			int j = i;
			while (ah[j].left != 0)
				j = ah[j].left;
			if (rmost != 0)
				ah[j].left = rmost;
			if (lmost != NULL)
				lmost->right = j;
			sel[j] = true;
			while (ah[j].right != 0)
			{
				j = ah[j].right;
				sel[j] = true;
			}
			lmost = &(ah[j]);
			rmost = j;
		}
	for (int i = 1; i <= n; i++)
		cout << ah[i].left << " " << ah[i].right << endl;
	return 0;
}