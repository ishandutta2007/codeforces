uses math;
var
    kol,f:array[1..10001] of longint; ans,n,i:longint;


procedure inputdata;
var i,c:longint;
begin
  assign(input,'input.txt'); reset(input);
  readln(n);
  for i:=1 to n do
    begin
      read(c);
      inc(kol[c]);
    end;
  close(input);
end;


procedure outputdata;
begin
  assign(output,'output.txt'); rewrite(output);
  writeln(ans);
  close(output);
end;


begin

  inputdata;
  for i:=5000 downto 1 do f[i]:=f[i+1]+kol[i];
  ans:=maxlongint;
  for i:=1 to 5000 do
    if kol[i]<>0 then ans:=min(ans,n-(f[i]-f[i*2+1]));
  outputdata;

end.