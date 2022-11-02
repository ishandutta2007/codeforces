uses math;
var
  a,s,t:array[0..200000] of longint; ans,size,i,n:longint;


procedure modify;
begin
  while (size<n) and (s[size]>s[size+1]) do
  begin
    s[size+1]:=s[size]; t[size+1]:=max(t[size]+1,t[size+1]);
    inc(size);
  end;
end;


begin

  readln(n); for i:=1 to n do read(a[i]);
  size:=n; s[n]:=a[n];
  for i:=n-1 downto 1 do
  begin
    if a[i]>s[size] then
    begin
      s[size]:=a[i];
      t[size]:=1;
    end
      else
    begin
      modify;
      dec(size); s[size]:=a[i];
    end;
  end;
  modify;
  for i:=1 to n do if t[i]>ans then ans:=t[i];
  writeln(ans);

end.