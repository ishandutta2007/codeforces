#include <stdio.h>
#include <math.h>

double a, d;
int n;

int main() {
	scanf("%lf%lf%d", &a, &d, &n);
	double x = 0, y = 0;
	int di = 0;
	while(d > 4*a) {
		d -= 4*a;
	}
	for(int i = 0;i < n;i++) {
		if(di == 0) {
			x += d;
		}else if(di == 1) {
			y += d;			
		}else if(di == 2) {
			x -= d;
		}else {
			y -= d;
		}
		if(x > a) {
			y = x-a;
			x = a;
			di = 1;
		}
		if(y > a) {
			x = a-(y-a);
			y = a;
			di = 2;
		}
		if(x < 0) {
			y = a + x;
			x = 0;
			di = 3;
		}
		if(y < 0) {
			x = -y;
			y = 0;
			di = 0;
		}
		if(x > a) {
			y = x-a;
			x = a;
			di = 1;
		}
		if(y > a) {
			x = a-(y-a);
			y = a;
			di = 2;
		}
		if(x < 0) {
			y = a + x;
			x = 0;
			di = 3;
		}
		if(y < 0) {
			x = -y;
			y = 0;
			di = 0;
		}
		
		printf("%.6lf %.6lf\n", x, y);	
	}
	return 0;
}