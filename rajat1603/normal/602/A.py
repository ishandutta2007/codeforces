n , b1 = map(int , raw_input().split())
str1 = map(int , raw_input().split())
num1 = 0
for i in range(0 , n):
	num1 = num1 * b1 + str1[i]
m , b2 = map(int , raw_input().split())
str2 = map(int , raw_input().split())
num2 = 0
for i in range(0 , m):
	num2 = num2 * b2 + str2[i]
if num1 < num2:
	print '<'
elif num1 > num2:
	print '>'
else:
	print '='