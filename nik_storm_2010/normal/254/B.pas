const months:array[1..12] of longint = (31,28,31,30,31,30,31,31,30,31,30,31);
var
    mas:array[1..3,1..100] of longint; answer,tek,n,i,j:longint;


procedure find(a,b:longint; var tek:longint);
var i:longint;
begin
  tek:=b;
  for i:=1 to a-1 do tek:=tek+months[i];
end;


procedure inputdata;
var a,b,i:longint;
begin
  assign(input,'input.txt'); reset(input);
  readln(n);
  for i:=1 to n do
    begin
      readln(a,b,mas[2,i],mas[3,i]);
      find(a,b,mas[1,i]);
    end;
  close(input);
end;


procedure outputdata;
begin
  assign(output,'output.txt'); rewrite(output);
  writeln(answer);
  close(output);
end;


begin

  inputdata; answer:=0;
  for i:=-100 to 365 do
    begin
      tek:=0;
      for j:=1 to n do
        if (mas[1,j]-mas[3,j]<=i) and (i<=mas[1,j]-1) then tek:=tek+mas[2,j];
      if answer<tek then answer:=tek;
    end;
  outputdata;

end.