var
  a,b:array[1..200000] of longint; ans,n,i,c:longint;


begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
  begin
    read(c);
    b[c]:=i;
  end;
  ans:=0;
  for i:=1 to n-1 do if (b[a[i]]>b[a[i+1]]) then begin ans:=n-i; break; end;
  writeln(ans);
end.