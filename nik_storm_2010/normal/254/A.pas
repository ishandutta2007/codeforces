var
    a:array[1..2,1..600000] of longint; n,i:longint;


procedure inputdata;
var i:longint;
begin
  assign(input,'input.txt'); reset(input);
  readln(n);
  for i:=1 to 2*n do
    begin
      read(a[1,i]); a[2,i]:=i;
    end;
  close(input);
end;


procedure quicksort(l,r:longint);
var tmp,i,j,d:longint;
begin
  i:=l; j:=r; d:=a[1,random(r-l+1)+l];
  while i<=j do
    begin
      while a[1,i]<d do inc(i);
      while a[1,j]>d do dec(j);
      if i<=j then
        begin
          tmp:=a[1,i]; a[1,i]:=a[1,j]; a[1,j]:=tmp;
          tmp:=a[2,i]; a[2,i]:=a[2,j]; a[2,j]:=tmp;
          inc(i); dec(j);
        end;
    end;
  if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
end;


begin

  inputdata; randomize; quicksort(1,2*n);
  assign(output,'output.txt'); rewrite(output);
  for i:=1 to n do
    if a[1,i*2-1]<>a[1,i*2] then
    begin
      writeln(-1); close(output);
      halt;
    end;
  for i:=1 to n do writeln(a[2,i*2-1],' ',a[2,i*2]);
  close(output);

end.