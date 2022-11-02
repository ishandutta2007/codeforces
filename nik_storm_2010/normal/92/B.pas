program B92;
var
  masv : array[1..1000010] of integer;
  long,i,answer,j : longint;


procedure inputdata;
var i,d,code:longint;
     s:ansistring;
 begin
  readln(s);
   d:=length(s);
    for i:=d downto 1 do
     val(s[i],masv[d-i+1],code);
  long:=d;
 end;


Begin

  inputdata;

  i:=1;
   answer:=0;
    while long<>1 do
     begin
      if masv[i]=0
       then
        begin
         inc(answer);
          inc(i);
           dec(long);
        end
       else
        begin
         inc(answer);
          j:=i;
           while masv[j]=1 do
            begin
             masv[j]:=0;
              inc(j);
            end;
           masv[j]:=1;
         if masv[long+i]=1 then inc(long);
        end;

     end;

  writeln(answer);

End.