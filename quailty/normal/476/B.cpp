#include<stdio.h>
#include<math.h>
#include<string.h>
int fact(int n)
{
	int fact, i;
	fact = 1;
	for (i = 1; i <= n; i++)fact = fact*i;
	return fact;
}
int main()
{
	char s1[11], s2[11];
	int i, sit1, sit2, t, reminder;
	double ratio;
	scanf("%s", &s1);
	scanf("%s", &s2);
	sit1 = 0;
	sit2 = 0;
	t = 0;
	for (i = 0; i <= strlen(s1) - 1; i++){
		if (s1[i] == '+')sit1 = sit1 + 1;
		if (s1[i] == '-')sit1 = sit1 - 1;
	}
	for (i = 0; i <= strlen(s2) - 1; i++){
		if (s2[i] == '+')sit2 = sit2 + 1;
		if (s2[i] == '-')sit2 = sit2 - 1;
		if (s2[i] == '?')t = t + 1;
	}
	reminder =(sit1 - sit2 + t) / 2;
	if (reminder<0 || reminder >t)ratio = 0;
	else
	ratio = (double)(fact(t) / (fact(reminder)*fact(t - reminder))) / pow((double)2, t);
	printf("%.12f\n", ratio);
	return 0;
}