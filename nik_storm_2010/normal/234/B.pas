var
    a,b:array[1..1000] of longint; tmp,n,k,i,j:longint;


procedure inputdata;
var i:longint;
begin
  assign(input,'input.txt'); reset(input);
  readln(n,k);
  for i:=1 to n do
    begin
      read(a[i]); b[i]:=i;
    end;
  close(input);
end;


procedure outputdata;
var i:longint;
begin
  assign(output,'output.txt'); rewrite(output);
  writeln(a[n-k+1]);
  for i:=n-k+1 to n do write(b[i],' ');
  close(output);
end;


begin

  inputdata;
  for i:=1 to n do
    for j:=i+1 to n do
      if a[i]>a[j] then
      begin
        tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
        tmp:=b[i]; b[i]:=b[j]; b[j]:=tmp;
      end;
  outputdata;

end.