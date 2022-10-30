program storm;
var s1,s2,s3:string;


procedure inputdata;
begin
 readln(s1);
 readln(s2);
 readln(s3);
end;

procedure outputdata(c:char);
begin
 writeln(c);
end;

begin
 inputdata;
  if (s1='rock')    and (s2='rock')     and (s3='rock')        then begin outputdata('?'); halt; end;
 if (s1='rock')     and (s2='rock')     and (s3='paper')       then begin outputdata('S'); halt; end;
 if (s1='rock')     and (s2='rock')     and (s3='scissors')    then begin outputdata('?'); halt; end;
 if (s1='rock')     and (s2='paper')    and (s3='rock')        then begin outputdata('M'); halt; end;
 if (s1='rock')     and (s2='paper')    and (s3='paper')       then begin outputdata('?'); halt; end;
 if (s1='rock')     and (s2='paper')    and (s3='scissors')    then begin outputdata('?'); halt; end;
 if (s1='rock')     and (s2='scissors') and (s3='rock')        then begin outputdata('?'); halt; end;
 if (s1='rock')     and (s2='scissors') and (s3='paper')       then begin outputdata('?'); halt; end;
 if (s1='rock')     and (s2='scissors') and (s3='scissors')    then begin outputdata('F'); halt; end;
 if (s1='paper')    and (s2='rock')     and (s3='rock')        then begin outputdata('F'); halt; end;
 if (s1='paper')    and (s2='rock')     and (s3='paper')       then begin outputdata('?'); halt; end;
 if (s1='paper')    and (s2='rock')     and (s3='scissors')    then begin outputdata('?'); halt; end;
 if (s1='paper')    and (s2='paper')    and (s3='rock')        then begin outputdata('?'); halt; end;
 if (s1='paper')    and (s2='paper')    and (s3='paper')       then begin outputdata('?'); halt; end;
 if (s1='paper')    and (s2='paper')    and (s3='scissors')    then begin outputdata('S'); halt; end;
 if (s1='paper')    and (s2='scissors') and (s3='rock')        then begin outputdata('?'); halt; end;
 if (s1='paper')    and (s2='scissors') and (s3='paper')       then begin outputdata('M'); halt; end;
 if (s1='paper')    and (s2='scissors') and (s3='scissors')    then begin outputdata('?'); halt; end;
 if (s1='scissors') and (s2='rock')     and (s3='rock')        then begin outputdata('?'); halt; end;
 if (s1='scissors') and (s2='rock')     and (s3='paper')       then begin outputdata('?'); halt; end;
 if (s1='scissors') and (s2='rock')     and (s3='scissors')    then begin outputdata('M'); halt; end;
 if (s1='scissors') and (s2='paper')    and (s3='rock')        then begin outputdata('?'); halt; end;
 if (s1='scissors') and (s2='paper')    and (s3='paper')       then begin outputdata('F'); halt; end;
 if (s1='scissors') and (s2='paper')    and (s3='scissors')    then begin outputdata('?'); halt; end;
 if (s1='scissors') and (s2='scissors') and (s3='rock')        then begin outputdata('S'); halt; end;
 if (s1='scissors') and (s2='scissors') and (s3='paper')       then begin outputdata('?'); halt; end;
 if (s1='scissors') and (s2='scissors') and (s3='scissors')    then begin outputdata('?'); halt; end;




end.