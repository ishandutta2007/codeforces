#include<stdio.h>
#include<string.h>
int main()
{
	int i;
	char a,s[101];
	a = getchar();
	scanf("%s", &s);
	if (a == 'L')
	{
		for (i = 0; i <= strlen(s) - 1; i++)
		{
			if (s[i] == 'q'){
				s[i] = 'w';
				continue;
			}
			if (s[i] == 'w'){
				s[i] = 'e';
				continue;
			}
			if (s[i] == 'e'){
				s[i] = 'r';
				continue;
			}
			if (s[i] == 'r'){
				s[i] = 't';
				continue;
			}
			if (s[i] == 't'){
				s[i] = 'y';
				continue;
			}
			if (s[i] == 'y'){
				s[i] = 'u';
				continue;
			}
			if (s[i] == 'u'){
				s[i] = 'i';
				continue;
			}
			if (s[i] == 'i'){
				s[i] = 'o';
				continue;
			}
			if (s[i] == 'o'){
				s[i] = 'p';
				continue;
			}
			if (s[i] == 'a'){
				s[i] = 's';
				continue;
			}
			if (s[i] == 's'){
				s[i] = 'd';
				continue;
			}
			if (s[i] == 'd'){
				s[i] = 'f';
				continue;
			}
			if (s[i] == 'f'){
				s[i] = 'g';
				continue;
			}
			if (s[i] == 'g'){
				s[i] = 'h';
				continue;
			}
			if (s[i] == 'h'){
				s[i] = 'j';
				continue;
			}
			if (s[i] == 'j'){
				s[i] = 'k';
				continue;
			}
			if (s[i] == 'k'){
				s[i] = 'l';
				continue;
			}
			if (s[i] == 'l'){
				s[i] = ';';
				continue;
			}
			if (s[i] == 'z'){
				s[i] = 'x';
				continue;
			}
			if (s[i] == 'x'){
				s[i] = 'c';
				continue;
			}
			if (s[i] == 'c'){
				s[i] = 'v';
				continue;
			}
			if (s[i] == 'v'){
				s[i] = 'b';
				continue;
			}
			if (s[i] == 'b'){
				s[i] = 'n';
				continue;
			}
			if (s[i] == 'n'){
				s[i] = 'm';
				continue;
			}
			if (s[i] == 'm'){
				s[i] = ',';
				continue;
			}
			if (s[i] == ','){
				s[i] = '.';
				continue;
			}
			if (s[i] == '.'){
				s[i] = '/';
				continue;
			}
		}
		printf("%s\n", s);
	}
	if (a == 'R')
	{
		for (i = 0; i <= strlen(s) - 1; i++)
		{
			if (s[i] == 'w')s[i] = 'q';
			if (s[i] == 'e')s[i] = 'w';
			if (s[i] == 'r')s[i] = 'e';
			if (s[i] == 't')s[i] = 'r';
			if (s[i] == 'y')s[i] = 't';
			if (s[i] == 'u')s[i] = 'y';
			if (s[i] == 'i')s[i] = 'u';
			if (s[i] == 'o')s[i] = 'i';
			if (s[i] == 'p')s[i] = 'o';
			if (s[i] == 's')s[i] = 'a';
			if (s[i] == 'd')s[i] = 's';
			if (s[i] == 'f')s[i] = 'd';
			if (s[i] == 'g')s[i] = 'f';
			if (s[i] == 'h')s[i] = 'g';
			if (s[i] == 'j')s[i] = 'h';
			if (s[i] == 'k')s[i] = 'j';
			if (s[i] == 'l')s[i] = 'k';
			if (s[i] == ';')s[i] = 'l';
			if (s[i] == 'x')s[i] = 'z';
			if (s[i] == 'c')s[i] = 'x';
			if (s[i] == 'v')s[i] = 'c';
			if (s[i] == 'b')s[i] = 'v';
			if (s[i] == 'n')s[i] = 'b';
			if (s[i] == 'm')s[i] = 'n';
			if (s[i] == ',')s[i] = 'm';
			if (s[i] == '.')s[i] = ',';
			if (s[i] == '/')s[i] = '.';
		}
		printf("%s\n", s);
	}
	return 0;
}