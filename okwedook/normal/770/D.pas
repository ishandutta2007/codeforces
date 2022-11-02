const SIZE = 1000;

type
 str = array[1..SIZE]of char;
 
var
 ans:array[1..SIZE]of str;
 level:array[1..SIZE]of integer;
 n,i,j,max,ptr,count,min,cur,x:integer;
 s:string;

procedure print(arr:str);
var
 i,t:integer;
begin
 t := 0;
 for i := 1 to SIZE do
  if arr[i] <> ' ' then
   t := i; 
 for i := 1 to t do
  write(arr[i]);
 writeln;
end;

procedure add(x, l:integer; c:char);
var
 i:integer;
begin
 for i := level[1]+1-l to level[1]+2+l do
  ans[i][x] := '|';
 ans[level[1]+1-l][x]:='+';
 ans[level[1]+3+l][x]:='+';
 if c = '[' then
 begin 
  ans[level[1]+1-l][x + 1]:='-';
  ans[level[1]+3+l][x + 1]:='-';
 end
 else
 begin
  ans[level[1]+1-l][x - 1]:='-';
  ans[level[1]+3+l][x - 1]:='-';
 end;
end;

begin
 readln(n);
 readln(s);
 for i:=1 to SIZE do
  for j:=1 to SIZE do
   ans[i][j] := ' ';
 cur := 1;
 for i := 1 to n do
 begin
  if s[i] = '[' then
   dec(cur);
  level[i] := cur;
  if s[i] = ']' then
   inc(cur)
 end;
 min := SIZE;
 for i := 1 to SIZE do
  if(level[i] < min)then
   min := level[i];
 for i := 1 to n do
  dec(level[i], min);
 x := 1; 
 ptr := 1;
 add(x, level[ptr], s[ptr]);
 while(ptr < n)do
 begin
  inc(ptr);
  if s[ptr] = s[ptr-1] then
   inc(x)
  else
   if(s[ptr] = '[')then
    inc(x)
   else
    inc(x, 4);
  add(x, level[ptr], s[ptr]);
 end;
 for i := 1 to 3 + level[1] * 2 do
  print(ans[i]);
end.