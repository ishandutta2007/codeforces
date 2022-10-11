a = '''((
min
(
i
,
25
)
+
i
)
%
(
2
+
i
%
3
))
>
0'''

for i in range(21,51):
    print int(eval(a.replace('\n','')))