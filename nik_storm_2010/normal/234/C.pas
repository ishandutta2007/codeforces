uses math;
var
    a,b,c:array[0..100000] of longint; answer,tek,n,i:longint;


procedure inputdata;
begin
  assign(input,'input.txt'); reset(input);
  readln(n);
  for i:=1 to n do read(a[i]);
  close(input);
end;


procedure outputdata;
begin
  assign(output,'output.txt'); rewrite(output);
  writeln(answer);
  close(output);
end;


begin

  inputdata;
  for i:=1 to n do
    begin
      b[i]:=b[i-1]; if a[i]<0 then inc(b[i]);
      c[i]:=c[i-1]; if a[i]>0 then inc(c[i]);
    end;
  answer:=maxlongint;
  for i:=1 to n-1 do
    begin
      tek:=(i-b[i]) + ((n-i)-(c[n]-c[i]));
      answer:=min(answer,tek);
    end;
  outputdata;

end.