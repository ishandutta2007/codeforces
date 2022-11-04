#include<stdio.h>
long x[100][4][4], y[100][4][4], a[100][4][4], b[100][4][4];
int main()
{
	long n, i, j, count;
	double c[6],used[2];
	int p, q, r, s, cl[2], temp;
	scanf("%ld", &n);
	for (i = 0; i <= n - 1; i++){
		for (j = 0; j <= 3; j++){
			scanf("%ld%ld%ld%ld", &x[i][j][0], &y[i][j][0], &a[i][j][0], &b[i][j][0]);
			x[i][j][1] = a[i][j][0] + b[i][j][0] - y[i][j][0];
			y[i][j][1] = x[i][j][0] + b[i][j][0] - a[i][j][0];
			x[i][j][2] = 2 * a[i][j][0] - x[i][j][0];
			y[i][j][2] = 2 * b[i][j][0] - y[i][j][0];
			x[i][j][3] = a[i][j][0] + y[i][j][0] - b[i][j][0];
			y[i][j][3] = a[i][j][0] + b[i][j][0] - x[i][j][0];
		}
	}
	for (i = 0; i <= n - 1; i++){
		count = -1;
		temp = -1;
		for (p = 0; p <= 3; p++){
			for (q = 0; q <= 3; q++){
				for (r = 0; r <= 3; r++){
					for (s = 0; s <= 3; s++)
					{
						used[0] = -1;
						used[1] = -1;
						cl[0] = 0;
						cl[1] = 0;
						c[0] = (double)(x[i][0][p] - x[i][1][q])*(x[i][0][p] - x[i][1][q]) + (double)(y[i][0][p] - y[i][1][q])*(y[i][0][p] - y[i][1][q]);
						c[1] = (double)(x[i][0][p] - x[i][2][r])*(x[i][0][p] - x[i][2][r]) + (double)(y[i][0][p] - y[i][2][r])*(y[i][0][p] - y[i][2][r]);
						c[2] = (double)(x[i][0][p] - x[i][3][s])*(x[i][0][p] - x[i][3][s]) + (double)(y[i][0][p] - y[i][3][s])*(y[i][0][p] - y[i][3][s]);
						c[3] = (double)(x[i][1][q] - x[i][2][r])*(x[i][1][q] - x[i][2][r]) + (double)(y[i][1][q] - y[i][2][r])*(y[i][1][q] - y[i][2][r]);
						c[4] = (double)(x[i][1][q] - x[i][3][s])*(x[i][1][q] - x[i][3][s]) + (double)(y[i][1][q] - y[i][3][s])*(y[i][1][q] - y[i][3][s]);
						c[5] = (double)(x[i][2][r] - x[i][3][s])*(x[i][2][r] - x[i][3][s]) + (double)(y[i][2][r] - y[i][3][s])*(y[i][2][r] - y[i][3][s]);
						used[0] = c[0];
						for (j = 0; j <= 5; j++){
							if (c[j] > 0){
								if (c[j] == used[0])cl[0] = cl[0] + 1;
								if (c[j] != used[0] && used[1] == -1)
									used[1] = c[j];
								if (c[j] != used[0] && used[1] != -1){
									if (c[j] == used[1])cl[1] = cl[1] + 1;
									else break;
								}
							}
						}

						if (cl[0] + cl[1] == 6){
							if (cl[0] == 2 || cl[1] == 2){
								temp = p + q + r + s;
							}
							if (temp >= 0)
							if (count < 0 || temp <= count)
								count = temp;
						}
					}
				}
			}
		}
		printf("%ld\n", count);
	}
	return 0;
}