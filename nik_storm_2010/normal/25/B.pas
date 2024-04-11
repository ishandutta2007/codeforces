program storm;
var n:longint;
    s:string;


procedure inputdata;
begin
 readln(n);
 readln(s);
end;

procedure outputdata;
var d,d1,i:longint;
    s1:string;
begin
 d:=length(s); s1:='';
 if d mod 2 = 0 then
     begin
     i:=1;
     while i<d do begin s1:=s1+copy(s,i,2)+'-'; inc(i,2); end;
     end
                else
     begin
     i:=4;
     s1:=copy(s,1,3)+'-';
     while i<d do begin s1:=s1+copy(s,i,2)+'-'; inc(i,2); end;
     end;
 d1:=length(s1); delete(s1,d1,1);
 writeln(s1);
end;

begin
 inputdata;
 outputdata;
end.